package game.widgets;

import javafx.geometry.Pos;
import javafx.scene.layout.VBox;

public class GameRoot extends VBox
{
    public String player;

    public GameRoot() {
        super(10);
        player = "Player";
        setMinSize(600, 300);
        setAlignment(Pos.CENTER);
    }

    public void setPlayerName(String name) {
        player = name;
    }
}
