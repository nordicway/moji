package it.zielke.moji;

/**
 * Internal stage of the client. Describes the imperative nature of the MOSS
 * service, eg. the client cannot ask the server for results if no files have
 * been sent.
 * 
 * @see SocketClient#getCurrentStage()
 * 
 */
public enum Stage {

	DISCONNECTED, AWAITING_INITIALIZATION, AWAITING_LANGUAGE, AWAITING_FILES, AWAITING_QUERY, AWAITING_RESULTS, AWAITING_END;

}
