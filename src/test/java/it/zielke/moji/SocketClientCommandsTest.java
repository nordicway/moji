package it.zielke.moji;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.fail;

import java.io.File;
import java.net.URL;

import org.apache.commons.io.FileUtils;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class SocketClientCommandsTest extends SocketClientTestBase {

	@Before
	public void setUp() throws Exception {
		super.setUp();
	}

	@After
	public void tearDown() throws Exception {
		super.tearDown();
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
	public void testSendCommand() {

		String[] commandString = { "language", "java" };
		assertEquals("language java\n", sendStringCommands(commandString));

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
		return new junit.framework.JUnit4TestAdapter(
				SocketClientCommandsTest.class);
	}

}
