package it.zielke.moji;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.MalformedURLException;
import java.net.Socket;
import java.net.URL;
import java.net.UnknownHostException;
import java.util.Arrays;
import java.util.List;
import java.util.Locale;
import java.util.Vector;

import org.apache.commons.io.Charsets;
import org.apache.commons.io.FileUtils;

/**
 * Client for communicating with the MOSS server socket. Handles the
 * configuration, sending of files and receiving results.
 */
public class SocketClient {
	private static final String MESSAGE_UNKNOWN_LANGUAGE = "MOSS Server does not recognize this programming language";
	private static final String DEFAULT_LANGUAGE = "java";
	private static final int STARTING_SETID = 1;

	private Socket socket;
	private Stage currentStage = Stage.DISCONNECTED;

	private String server;
	private int port;
	private String userID;
	private String language;
	private int setID = STARTING_SETID;
	private long optM = 10;
	private int optD = 1;
	private int optX = 0;
	private long optN = 250;
	private String optC = "";
	private URL resultURL;
	private List<String> supportedLanguages = Arrays.asList("c", "cc", "java",
			"ml", "pascal", "ada", "lisp", "schema", "haskell", "fortran",
			"ascii", "vhdl", "perl", "matlab", "python", "mips", "prolog",
			"spice", "vb", "csharp", "modula2", "a8086", "javascript", "plsql");

	private SocketPrintWriter out;
	private BufferedReader in;

	/**
	 * Construct socket client with default host, port and programming language
	 * of the source files to be uploaded. Default language is Java.
	 */
	public SocketClient() {
		this.server = "moss.stanford.edu";
		this.port = 7690;
		this.language = DEFAULT_LANGUAGE;
	}

	/**
	 * Construct socket client by setting a server and port.
	 * 
	 * @param server
	 *            host name or IP of the MOSS server
	 * @param port
	 *            port of the MOSS server
	 */
	public SocketClient(String server, int port) {
		this();
		this.server = server;
		this.port = port;
	}

	/**
	 * Construct socket client by setting a server name and port as well as the
	 * programming language of the source files.
	 * 
	 * @param server
	 *            host name or IP of the MOSS server
	 * @param port
	 *            port of the MOSS server
	 * @param language
	 *            programming language of all source files
	 */
	public SocketClient(String server, int port, String language) {
		this(server, port);
		this.language = language;
	}

	/**
	 * Close connection to the MOSS server gracefully.
	 */
	public void close() {
		/*
		 * do not check stage here so clients can close a connection in any
		 * situation.
		 */
		try {
			sendCommand("end\n");
			out.close();
			in.close();
			socket.close();
		} catch (MossException e) {
		} catch (IOException e2) {
		} finally {
			currentStage = Stage.DISCONNECTED;
		}

	}

	/**
	 * Connect to the MOSS server and set the input and output streams for
	 * communication.
	 * 
	 * @throws UnknownHostException
	 *             if host resolution fails
	 * @throws IOException
	 *             if setting up the input streams fails
	 * @throws SecurityException
	 *             if a connection is disallowed by your security manager
	 */
	public void connect() throws UnknownHostException, IOException,
			SecurityException {
		if (currentStage != Stage.DISCONNECTED) {
			throw new RuntimeException("Client is already connected");
		}
		socket = new Socket(this.server, this.port);
		socket.setKeepAlive(true);
		out = new SocketPrintWriter(socket.getOutputStream(), true);
		in = new BufferedReader(new InputStreamReader(socket.getInputStream(),
				Charsets.US_ASCII));
		currentStage = Stage.AWAITING_INITIALIZATION;
	}

	/**
	 * @return the current internal stage of the client.
	 */
	public Stage getCurrentStage() {
		return currentStage;
	}

	/**
	 * Increment the set ID internally. Do not increment this manually unless
	 * you have a good reason. Might be removed in the future.
	 * 
	 * @return the last set ID, before this increment.
	 */
	@Deprecated
	public int getIncSetID() {
		return setID++;
	}

	public String getLanguage() {
		return language;
	}

	public String getOptC() {
		return optC;
	}

	public int getOptD() {
		return optD;
	}

	public long getOptM() {
		return optM;
	}

	public long getOptN() {
		return optN;
	}

	public int getOptX() {
		return optX;
	}

	public int getPort() {
		return port;
	}

	/**
	 * @return the URL which points to the plagiarism report, located on the
	 *         MOSS web server.
	 */
	public URL getResultURL() {
		return resultURL;
	}

	public String getServer() {
		return server;
	}

	public int getSetID() {
		return setID;
	}

	public Socket getSocket() {
		return socket;
	}

	/**
	 * @return a list of supported programming languages by the MOSS server.
	 */
	public List<String> getSupportedLanguages() {
		return supportedLanguages;
	}

	public String getUserID() {
		return userID;
	}

	/**
	 * Read a single line of the server's response.
	 * 
	 * @return the line read
	 * @throws IOException
	 *             if it was not possible to read from the socket
	 */
	public String readFromServer() throws IOException {
		return in.readLine();
	}

	/**
	 * Shortcut method to connect to the MOSS server, send all initialization
	 * parameters and set the programming language of all source files. Call
	 * this before uploading any files.
	 * 
	 * @throws MossException
	 *             if the MOSS server returns an error
	 * @throws IOException
	 *             if there is a (network) error while reading the server
	 *             response
	 * @throws UnknownHostException
	 *             if host resolution fails
	 */
	public void run() throws MossException, IOException, UnknownHostException {
		connect();
		sendInitialization();
		sendLanguage();
	}

	/**
	 * Generic function for sending all kinds of commands to the server.
	 * 
	 * @param objects
	 *            object array consisting of parameters which should be sent to
	 *            the server
	 * @return the generated string which was actually sent to the server
	 * @throws MossException
	 *             if the server response is unexpected
	 */
	private String sendCommand(Object... objects) throws MossException {
		// TODO test
		Vector<String> commandStrings = new Vector<String>();
		String[] commandArray = new String[commandStrings.size()];
		for (Object o : objects) {
			String s;
			s = o.toString();

			commandStrings.add(s);
		}
		return sendCommandStrings(commandStrings.toArray(commandArray));
	}

	/**
	 * Generic function for sending all kinds of commands to the server.
	 * 
	 * @param strings
	 *            string array consisting of parameters which should be sent to
	 *            the server
	 * @return the generated string which was actually sent to the server
	 * @throws MossException
	 */
	private String sendCommandStrings(String... strings) throws MossException {
		if (strings == null || strings.length == 0) {
			throw new MossException(
					"Failed to send command because it was empty.");
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < strings.length; i++) {
			String s = strings[i];
			sb.append(s);
			if (i != strings.length - 1) {
				sb.append(" ");
			}
		}
		out.println(sb.toString());

		return sb.toString();
	}

	/**
	 * Sends initialization commands to the server. Needs to be called after
	 * connecting to the server but before sending any files.
	 * 
	 * @throws MossException
	 */
	public void sendInitialization() throws MossException {
		if (currentStage != Stage.AWAITING_INITIALIZATION) {
			throw new RuntimeException(
					"Cannot send initialization. Client is either already initialized or not connected yet.");
		}
		sendCommand("moss", userID);
		sendCommand("directory", optD);
		sendCommand("X", optX);
		sendCommand("maxmatches", optM);
		sendCommand("show", optN);
		currentStage = Stage.AWAITING_LANGUAGE;
	}

	// this client only uses directory mode right now.
	// public void setOptD(int optD) {
	// this.optD = optD;
	// }

	/**
	 * Sends a command to the server to define the programming language of all
	 * source files. The language must be set beforehand using setLanguage().
	 * 
	 * @see it.zielke.moji.SocketClient#setLanguage(String)
	 * @throws MossException
	 *             if this language is not supported by the MOSS server
	 * @throws IOException
	 *             if there is an error while reading the server answer
	 */
	public void sendLanguage() throws MossException, IOException {
		if (currentStage != Stage.AWAITING_LANGUAGE) {
			throw new RuntimeException(
					"Language already sent or client is not initialized yet.");
		}
		sendCommand("language", language);
		// confirm valid language server-side
		String serverString;
		serverString = readFromServer();
		if (serverString == null
				|| !serverString.trim().toLowerCase(Locale.ENGLISH)
						.equals("yes")) {
			throw new MossException(MESSAGE_UNKNOWN_LANGUAGE);
		}
		currentStage = Stage.AWAITING_FILES;
	}

	/**
	 * Sends a command to the server to define the programming language of all
	 * source files.
	 * 
	 * @param language
	 *            the programming language of all source files
	 * @throws MossException
	 *             if this language is not supported by the MOSS server
	 * @throws IOException
	 *             if there is an error while reading the server answer
	 */
	public void sendLanguage(String language) throws MossException, IOException {
		setLanguage(language);
		sendLanguage();
	}

	/**
	 * Sends a command to tell the server that all files have been uploaded and
	 * the search for plagiarism can start. Waits for an answer from the server
	 * which may take some minutes.
	 * 
	 * @throws MossException
	 *             if there is an error when receiving results from the MOSS
	 *             server
	 * @throws IOException
	 *             if the server communication fails
	 */
	public void sendQuery() throws MossException, IOException {
		if (currentStage != Stage.AWAITING_QUERY) {
			throw new RuntimeException(
					"Cannot send query at this time. Connection is either not initialized or already closed");
		}
		if (setID == 1) {
			throw new MossException("You did not upload any files yet");
		}
		sendCommand(String.format("%s %d %s", "query", 0, optC));
		currentStage = Stage.AWAITING_RESULTS;
		// Query submitted, waiting for server's response
		String result = readFromServer();
		if (null != result
				&& result.toLowerCase(Locale.ENGLISH).startsWith("http")) {
			try {
				this.resultURL = new URL(result.trim());
			} catch (MalformedURLException e) {
				throw new MossException(
						"MOSS submission failed. The server did not return a valid URL with detection results.",
						e);
			}
			currentStage = Stage.AWAITING_END;
		} else {
			throw new MossException(
					"MOSS submission failed. The server did not return a valid URL with detection results.");
		}
	}

	/**
	 * Set the programming language of all source files.
	 * 
	 * @param language
	 *            the programming language in which source file is written in.
	 *            Valid programming languages are: c, cc, java, ml, pascal, ada,
	 *            lisp, schema, haskell, fortran, ascii, vhdl, perl, matlab,
	 *            python, mips, prolog, spice, vb, csharp, modula2, a8086,
	 *            javascript and plsql.
	 */
	public void setLanguage(String language) throws MossException {
		if (!supportedLanguages.contains(language)) {
			throw new MossException(MESSAGE_UNKNOWN_LANGUAGE);
		}
		this.language = language;
	}

	/**
	 * Sets a comment string which is attached to the MOSS report. Individual
	 * reports can then easily be distinguished.
	 * 
	 * @param optC
	 *            comment string
	 */
	public void setOptC(String optC) {
		this.optC = optC;
	}

	/**
	 * Set the maximum amount of times a source code passage may appear before
	 * it is ignored and treated as base code. This is a good way to detect
	 * base/template code usage within students' solutions while uploading base
	 * code is unsupported by this client. Corresponds to the -m parameter of
	 * the original client.
	 * 
	 * @param optM
	 *            times a passage may appear before it is ignored
	 */
	public void setOptM(long optM) {
		this.optM = optM;
	}

	/**
	 * Sets how many matches should be displayed in the MOSS results. Default is
	 * 250.
	 * 
	 * @param optN
	 *            how many matches to display
	 */
	public void setOptN(long optN) {
		this.optN = optN;
	}

	/**
	 * Setting this value to 1 enables the experimental MOSS server. This is
	 * pretty much untested. Default is 0.
	 * 
	 * @param optX
	 *            0 or 1. 0: regular MOSS server, 1: experimental MOSS server.
	 */
	public void setOptX(int optX) {
		this.optX = optX;
	}

	public void setPort(int port) {
		this.port = port;
	}

	public void setServer(String server) {
		this.server = server;
	}

	public void setSocket(Socket socket) {
		this.socket = socket;
	}

	/**
	 * Set the MOSS user id for authentication with the MOSS server.
	 * 
	 * @param userID
	 *            your personalized ID to authenticate with. It should look like
	 *            /[0-9]+/ and is available on the MOSS page located at
	 *            http://theory.stanford.edu/~aiken/moss/
	 */
	public void setUserID(String userID) {
		this.userID = userID;
	}

	/**
	 * Uploads a single file to the MOSS server.
	 * 
	 * @param file
	 *            the source code file to be uploaded
	 * @throws IOException
	 *             if the file could not be read
	 */
	public void uploadFile(File file) throws IOException {
		uploadFile(file, false);
	}

	/**
	 * Uploads a single base file to the MOSS server.
	 * 
	 * @param file
	 *            the base file to be uploaded
	 * @throws IOException
	 *             if the file could not be read
	 */
	public void uploadBaseFile(File file) throws IOException {
		uploadFile(file, true);
	}

	/**
	 * Uploads a single file to the MOSS server.
	 * 
	 * @param file
	 *            the source code file to be uploaded
	 * @param isBaseFile
	 *            true is base file. false otherwise.
	 * @throws IOException
	 *             if the file could not be read
	 */
	@edu.umd.cs.findbugs.annotations.SuppressWarnings(value = "VA_FORMAT_STRING_USES_NEWLINE", justification = "We do want platform-independent newline here.")
	public void uploadFile(File file, boolean isBaseFile) throws IOException {
		if (currentStage != Stage.AWAITING_FILES
				&& currentStage != Stage.AWAITING_QUERY) {
			throw new RuntimeException(
					"Cannot upload file. Client is either not initialized properly or the connection is already closed");
		}
		String fileString = FileUtils.readFileToString(file, Charsets.UTF_8);
		// replace to get Unix-style line endings and the same count as the
		// Perl script
		fileString = fileString.replace("\r\n", "\n");

		String uploadString = String.format("file %d %s %d %s\n", // format:
				isBaseFile ? 0 : getIncSetID(), // 1. setID
				language, // 2. language
				fileString.getBytes(Charsets.US_ASCII).length, // 3. size
				/*
				 * Use Unix-style path to remain consistent. TODO test this with
				 * non-local files, e.g. on network shares
				 */
				file.getAbsolutePath().replace("\\", "/")); // 4. file path
		System.out.println("uploading file: " + file.getAbsolutePath());
		out.print(uploadString);
		out.print(fileString);

		currentStage = Stage.AWAITING_QUERY;

	}

}
