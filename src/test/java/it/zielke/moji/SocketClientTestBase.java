package it.zielke.moji;

import static org.junit.Assert.fail;

import java.lang.reflect.Method;
import java.util.Arrays;
import java.util.List;

import org.junit.After;
import org.junit.Before;

public class SocketClientTestBase {

	public static final String TEST_IP = "127.0.0.1";

	protected SocketClient socketClient;
	protected MockServer mockServer;
	protected Thread ms;

	@Before
	public void setUp() throws Exception {
		try {
			ms = new Thread(mockServer = new MockServer());
			mockServer.setPort(0);
			ms.setDaemon(true);
			ms.start();
			while (!mockServer.isBound()) {
				Thread.sleep(10);
			}
			socketClient = new SocketClient();
			socketClient.setServer(TEST_IP);
			int mockServerPort = mockServer.getLocalPort();
			socketClient.setPort(mockServerPort);
			socketClient.setUserID("900000");
			socketClient.connect();
			status("Started test on port " + mockServerPort);
		} catch (Exception e) {
			e.printStackTrace();
			fail("Failed to setup test server/client pair due to Exception: "
					+ e.getMessage());
		}
	}

	@After
	public void tearDown() throws Exception {
		try {
			mockServer.setShutdown(true);
			socketClient.close();
		} catch (Exception e) {

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

	protected void status(String s) {
		System.out.println("SocketClient - "
				+ String.format("%d - %s", socketClient.getPort(), s));
	}

}
