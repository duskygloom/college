package game.widgets;

import javafx.geometry.Pos;
import javafx.scene.control.TextField;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;

public class PlayerField extends TextField {
    public PlayerField(String name) {
        super(name);
        setFont(Font.font("Consolas", FontWeight.BOLD, 24));
        setAlignment(Pos.CENTER_LEFT);
        setMinHeight(80);
    }
}
