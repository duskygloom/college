public class tictactoe
{
	static final int BOARDSIZE = 9;
	public static void main(String[] args) {
		
	}
}


enum BoardStates {Blank, Cross, Circle};


class MarkedPositionException extends Exception
{
	MarkedPositionException(int pos) {
		super(String.format("Position %d already marked.\n", pos));
	}
}


class Board
{
	BoardStates boardArray[] = new BoardStates[tictactoe.BOARDSIZE];

	void markPosition(int pos, BoardStates state) throws MarkedPositionException {
		/**
		 * returns false if already marked
		 * else returns true
		 */
		if (boardArray[pos] == BoardStates.Blank)
			boardArray[pos] = state;
		else throw new MarkedPositionException(pos);
	}

	void resetBoard() {
		/**
		 * sets all board content to Blank
		 */
		for (int i = 0; i < tictactoe.BOARDSIZE; i++)
			boardArray[i] = BoardStates.Blank;
	}
}
