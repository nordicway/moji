package it.zielke.moji;

import java.io.File;

/**
 * Represents a combination of file and byte strings as known-good values for
 * testing binary compatibility with the Moss client.
 * 
 */
public class ExpectedValues {

	private File file;

	private int bytesLength;

	private String bytesHex;

	public File getFile() {
		return file;
	}

	public ExpectedValues setFile(File file) {
		this.file = file;
		return this;
	}

	public int getBytesLength() {
		return bytesLength;
	}

	public ExpectedValues setBytesLength(int bytesLength) {
		this.bytesLength = bytesLength;
		return this;
	}

	public String getBytesHex() {
		return bytesHex;
	}

	public ExpectedValues setBytesHex(String bytesHex) {
		this.bytesHex = bytesHex.replaceAll("[^A-Za-z0-9]", "").toLowerCase();
		return this;
	}

}
