package it.zielke.moji;

import static org.junit.Assert.fail;

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

}
