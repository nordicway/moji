package it.zielke.moji;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.ByteBuffer;

import org.apache.commons.io.IOUtils;

public class MockServer implements Runnable {
	private boolean shutdown;
	private int port = 7690;
	private ServerSocket ss;
	private InputStream in;
	private OutputStreamWriter out;

	private String userID;
	private String language;
	private int setID;
	private long optM;
	private int optD;
	private int optX;
	private long optN;
	private String optC;
	private String resultURL = "http://moss.stanford.edu/results/20132013";

	// expected results for test
	ByteBuffer expectedBytes;
	ByteBuffer receivedBytes;
	String lastFileReceived;

	public MockServer() {
	}

	public void setExpectedBytes(byte[] expectedBytes) {
		this.expectedBytes = ByteBuffer.wrap(expectedBytes);
	}

	private void status(String s) {
		System.out.println(String.format("MockServer - %d - %s", this.port, s));
	}

	public void waitForCommand() throws Exception {
		String s = null;
		try {
			StringBuilder sb = new StringBuilder();
			for (int read = in.read(); read >= 0 && read != 10; read = in
					.read()) {
				sb.append(Character.toString((char) read));
			}
			s = sb.toString();
			status("found command string: " + s);
		} catch (Exception e) {
			throw new RuntimeException(e);
		}

		if (s != null) {
			status("received command: " + s);
			processCommand(s);
		}
	}

	public void processCommand(String s) throws Exception {
		String[] parts = s.split(" ");
		String command = parts[0];
		String parameter = "";
		if (parts.length > 0) {
			for (int i = 1; i < parts.length; i++) {
				parameter += parts[i];
				if (i != parts.length - 1) {
					parameter += " ";
				}
			}
		}
		parameter = parameter.trim();
		status("command: " + command + ", parameter: " + parameter);

		if (command.equals("language")) {
			this.setLanguage(parameter);
			out.write("yes\n");
			out.flush();
		} else if (command.equals("moss")) {
			this.setUserID(parameter);
		} else if (command.equals("X")) {
			this.setOptX(Integer.parseInt(parameter));
		} else if (command.equals("file")) {
			checkFileUpload(parameter);
		} else if (command.equals("query")) {
			out.write(this.resultURL + "\n");
			out.flush();
			status("sent url: " + this.resultURL);
		} else if (command.trim().equals("end")) {
			this.shutdown = true;
		}
	}

	public void checkFileUpload(String fileUploadString) {
		String[] parts = fileUploadString.split(" ");
		int id = Integer.valueOf(parts[0]);
		String language = parts[1];
		int size = Integer.valueOf(parts[2]);
		String fileName = parts[3];

		checkFileBytes(size);
		lastFileReceived = fileName;
	}

	public void checkFileBytes(int expectedSize) {
		receivedBytes = null;
		byte[] b = null;
		try {
			b = IOUtils.toByteArray(this.in, expectedSize);
		} catch (IOException e) {
			endConnection();
			throw new RuntimeException(e);
		}
		ByteBuffer buffer = ByteBuffer.wrap(b);
		if (expectedBytes != null) {
			if (buffer.array().length != this.expectedBytes.array().length) {
				endConnection();
				throw new RuntimeException(
						String.format(
								"Error during file upload: expected number of bytes do not match the actual number of bytes. Expected bytes: %d, actual bytes: %d",
								this.expectedBytes.array().length,
								b == null ? "n/a" : b.length));
			} else {
				receivedBytes = buffer;
			}
		}
	}

	public void endConnection() {
		try {
			this.in.close();
			this.out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public void startServer() {
		try {
			try {
				ss = new ServerSocket(port);
			} catch (Exception e) {
				e.printStackTrace();
			}
			status("listening for connection");
			Socket s = ss.accept();
			// s.setKeepAlive(true);
			// s.setSoTimeout(5000);
			status("accepted connection - remote port: " + s.getPort());
			in = s.getInputStream();
			out = new OutputStreamWriter(s.getOutputStream());
			while (!shutdown) {
				status("waiting for command");
				waitForCommand();
			}
			status("shutting down");
			s.close();
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			try {
				in.close();
				out.close();
				ss.close();
			} catch (IOException e) {
			}

		}
	}

	public boolean isBound() {
		return (this.ss != null && this.ss.isBound());
	}

	public int getPort() {
		return port;
	}

	public void setPort(int port) {
		this.port = port;
	}

	public ServerSocket getSs() {
		return ss;
	}

	public void setSs(ServerSocket ss) {
		this.ss = ss;
	}

	public OutputStreamWriter getOut() {
		return out;
	}

	public void setOut(OutputStreamWriter out) {
		this.out = out;
	}

	public String getUserID() {
		return userID;
	}

	public void setUserID(String userID) {
		this.userID = userID;
	}

	public String getLanguage() {
		return language;
	}

	public void setLanguage(String language) {
		this.language = language;
	}

	public int getSetID() {
		return setID;
	}

	public void setSetID(int setID) {
		this.setID = setID;
	}

	public long getOptM() {
		return optM;
	}

	public void setOptM(long optM) {
		this.optM = optM;
	}

	public int getOptD() {
		return optD;
	}

	public void setOptD(int optD) {
		this.optD = optD;
	}

	public int getOptX() {
		return optX;
	}

	public void setOptX(int optX) {
		this.optX = optX;
	}

	public long getOptN() {
		return optN;
	}

	public void setOptN(long optN) {
		this.optN = optN;
	}

	public String getOptC() {
		return optC;
	}

	public void setOptC(String optC) {
		this.optC = optC;
	}

	public String getResultURL() {
		return resultURL;
	}

	public void setResultURL(String resultURL) {
		this.resultURL = resultURL;
	}

	public void run() {
		status("ready to run");
		startServer();

	}

	public boolean isShutdown() {
		return shutdown;
	}

	public void setShutdown(boolean shutdown) {
		this.shutdown = shutdown;
	}

	public int getLocalPort() {
		return this.ss.getLocalPort();
	}

	public ByteBuffer getReceivedBytes() {
		return receivedBytes;
	}

	public String getLastFileReceived() {
		return lastFileReceived;
	}

}
