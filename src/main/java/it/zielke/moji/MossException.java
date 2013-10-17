package it.zielke.moji;

public class MossException extends Exception {
	private static final long serialVersionUID = -3296167322751430755L;
	private Exception origin;

	public MossException(String string) {
		super(string);
	}

	public MossException(String string, Exception origin) {
		this(string);
		this.setOrigin(origin);
	}

	public Exception getOrigin() {
		return origin;
	}

	public void setOrigin(Exception origin) {
		this.origin = origin;
	}

}
