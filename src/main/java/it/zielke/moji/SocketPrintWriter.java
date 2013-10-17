package it.zielke.moji;

import java.io.IOException;
import java.io.InterruptedIOException;
import java.io.OutputStream;
import java.io.PrintWriter;

/**
 * PrintWriter for use with the MOSS client. Always uses ordinary newline
 * character (\n) which makes it OS independent.
 * 
 */
public class SocketPrintWriter extends PrintWriter {

	public SocketPrintWriter(OutputStream out, boolean autoFlush) {
		super(out, autoFlush);
	}

	/** Checks to make sure that the stream has not been closed */
	private void ensureOpen() throws IOException {
		if (out == null) {
			throw new IOException("Stream closed");
		}
	}

	private void newLine() {
		try {
			synchronized (lock) {
				ensureOpen();
				// always write \n instead of depending on OS-specific settings
				out.write("\n");
				out.flush();
			}
		} catch (InterruptedIOException x) {
			Thread.currentThread().interrupt();
		} catch (IOException x) {
			// don't pass on exceptions. see PrintWriter javadoc for explanation
		}
	}

	@Override
	public void println() {
		this.newLine();
	}

}
