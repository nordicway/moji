package it.zielke.moji;

import static org.junit.Assert.fail;

import java.io.ByteArrayOutputStream;
import java.io.OutputStreamWriter;
import java.nio.charset.Charset;
import java.util.Locale;

import org.junit.Test;

public class EncodingTest {

	@Test
	public void testEncoding() {
		if (!Charset.isSupported("US-ASCII")) {
			fail("No ASCII charset support available (?!)");
		}
	}

	@Test
	public void testLocale() {
		boolean localeAvailable = false;
		for (String s : Locale.getISOCountries()) {
			if (s.toLowerCase().equals("us")) {
				localeAvailable = true;
				break;
			}
		}
		if (!localeAvailable) {
			fail("No US Locale available");
		}
	}

	@Test
	public void testDefaultCharset() {
		try {
			System.out.println("Java version: "
					+ System.getProperty("java.version"));
			System.out.println(String.format(
					"Java VM:\n\tvendor: %s\n\tname: %s",
					System.getProperty("java.vm.vendor"),
					System.getProperty("java.vm.name")));
			System.out.println(String.format(
					"OS:\n\tname: %s\n\tversion: %s\n\tarch: %s",
					System.getProperty("os.name"),
					System.getProperty("os.version"),
					System.getProperty("os.arch")));
			System.out.println("Encoding:");
			System.out
					.println("\tDefault Charset: " + Charset.defaultCharset());
			System.out.println("\tfile.encoding: "
					+ System.getProperty("file.encoding"));
			System.out.println("\tDefault Charset in Use: "
					+ getDefaultCharSet());
		} catch (SecurityException e) {
			System.out.println("WARN - Running under security manager: "
					+ e.getMessage());
			e.printStackTrace();
		}
	}

	private static String getDefaultCharSet() {
		OutputStreamWriter writer = new OutputStreamWriter(
				new ByteArrayOutputStream());
		String enc = writer.getEncoding();
		return enc;
	}

}
