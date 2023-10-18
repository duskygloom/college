package game.widgets;

import javafx.geometry.Pos;
import javafx.scene.control.Label;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;

public class PlayerLabel extends Label {
    public PlayerLabel(String name) {
        super(name);
        setFont(Font.font("Consolas", FontWeight.BOLD, 24));
        setAlignment(Pos.CENTER_LEFT);
        setMinHeight(80);
    }
}
