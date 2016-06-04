package it.zielke.moji;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.fail;

import java.io.File;
import java.lang.reflect.Method;
import java.net.URL;
import java.util.Arrays;
import java.util.List;
import java.util.Random;

import org.apache.commons.io.FileUtils;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class SocketClientTest {

	public static final String TEST_IP = "127.0.0.1";

	SocketClient socketClient;
	MockServer mockServer;
	Thread ms;
	int testPort = 20000;

	@Before
	public void setUp() throws Exception {
		try {
			testPort = new Random().nextInt(20000) + 30000;

			ms = new Thread(mockServer = new MockServer());
			mockServer.setPort(testPort);
			ms.setDaemon(true);
			ms.start();
			while (!mockServer.isBound()) {
				Thread.sleep(10);
			}
			socketClient = new SocketClient();
			socketClient.setServer(TEST_IP);
			socketClient.setPort(testPort);
			socketClient.setUserID("900000");
			socketClient.connect();
			status("Started test on port " + testPort);
		} catch (Exception e) {
			e.printStackTrace();
			fail("Failed to setup test server/client pair due to Exception: "
					+ e.getMessage());
		}
	}

	public String sendStringCommands(String[] strings) {
		// might as well make the function public to avoid this mess
		Method method = null;
		Object o = socketClient;
		try {
			method = o.getClass().getDeclaredMethod("sendCommandStrings",
					strings.getClass());
			method.setAccessible(true);
			return (String) method.invoke(o, new Object[] { strings });
		} catch (Exception e) {
			e.printStackTrace();
		}
		return null;
	}

	public String sendObjectCommands(Object[] objects) {
		// might as well make the function public to avoid this mess
		Method method = null;
		Object o = socketClient;

		List<Object> os = Arrays.asList(objects);
		os.toString();
		try {
			method = o.getClass().getDeclaredMethod("sendCommand",
					new Object[] {}.getClass());
			method.setAccessible(true);
			return (String) method.invoke(o, new Object[][] { objects });
		} catch (Exception e) {
			e.printStackTrace();
		}
		return null;
	}

	@After
	public void tearDown() throws Exception {
		try {
			mockServer.setShutdown(true);
			socketClient.close();
		} catch (Exception e) {

		}
	}

	@Test
	public void testSocketClient() {
		try {
			testSendQuery();
			testClose();
			assertEquals(Stage.DISCONNECTED, socketClient.getCurrentStage());
		} catch (Exception e) {
			fail(e.getMessage());
		}

	}

	@Test
	public void testSendInitialization() {
		try {
			assertEquals(Stage.AWAITING_INITIALIZATION,
					socketClient.getCurrentStage());
			socketClient.sendInitialization();
			assertEquals(Stage.AWAITING_LANGUAGE,
					socketClient.getCurrentStage());
		} catch (MossException e) {
			fail(e.getMessage());
		}

	}

	@Test
	public void testSetLanguage() {
		String invalidLanguage = "does_not_exist";
		String validLanguage = "java";

		try {
			socketClient.setLanguage(invalidLanguage);
		} catch (MossException e) {
			try {
				socketClient.setLanguage(validLanguage);
				return;
			} catch (MossException e1) {
				fail("Failed to accept a valid language");
			}
		}
		fail("Failed because an invalid language was accepted");

	}

	@Test
	public void testSendLanguage() {
		try {
			socketClient.sendInitialization();
			assertEquals(Stage.AWAITING_LANGUAGE,
					socketClient.getCurrentStage());
			socketClient.sendLanguage();
			assertEquals(Stage.AWAITING_FILES, socketClient.getCurrentStage());
			status("Test sendLanguage finished");
		} catch (Exception e) {
			fail(e.getMessage());
		}
		status("sent language");
	}

	private void status(String s) {
		System.out.println("SocketClient - "
				+ String.format("%d - %s", socketClient.getPort(), s));
	}

	@Test
	public void testUploadFile() {
		/*
		 * TODO implement with a file mock object. The test below will fail if
		 * no temporary file can be created.
		 */
		File tempFile = null;
		try {
			testSendLanguage();
			tempFile = File.createTempFile("MOJITest", ".java");
			socketClient.uploadFile(tempFile);
		} catch (Exception e) {
			e.printStackTrace();
			fail(e.getMessage());
		} finally {
			FileUtils.deleteQuietly(tempFile);
		}

	}

	@Test
	public void testSendQuery() {
		try {
			testUploadFile();
			socketClient.sendQuery();
			assertEquals(Stage.AWAITING_END, socketClient.getCurrentStage());
		} catch (Exception e) {
			fail(e.getMessage());
		}
	}

	@Test
	public void testGetResultURL() {
		try {
			testSendQuery();
			URL resultURL = socketClient.getResultURL();
			assertEquals(new MockServer().getResultURL(), resultURL.toString());
		} catch (Exception e) {
			fail(e.getMessage());
		}
	}

	@Test
	public void testClose() {
		assertEquals(mockServer.isShutdown(), false);
		try {
			socketClient.close();
		} catch (Exception e) {
			fail(e.getMessage());
		}
		assertEquals(Stage.DISCONNECTED, socketClient.getCurrentStage());
	}

	@Test
	public void testReadFromServer() {
	}

	@Test
	public void testRun() {

	}

	@Test
	public void testSendCommand() {

		String[] commandString = { "language", "java" };
		assertEquals("language java", sendStringCommands(commandString));

		// TODO rewrite the whole test without using reflection
		// Object[] commandObjects = { "directory", 1 };
		// assertEquals("directory 1", sendObjectCommands(commandObjects));
	}

	@Test
	public void testGetSocket() {
		if (socketClient.getSocket() == null
				|| socketClient.getSocket().isBound() == false) {
			fail("no connection to Server");
		}
	}

	@Test
	public void testGetIncSetID() {
		int current = socketClient.getSetID();
		assertEquals(socketClient.getIncSetID(), current);
		assertEquals(socketClient.getSetID(), current + 1);
	}

	public static junit.framework.Test suite() {
		return new junit.framework.JUnit4TestAdapter(SocketClientTest.class);
	}

}
