package game.widgets;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.layout.HBox;
import javafx.scene.text.Font;

public class MoveTable extends HBox 
{
    public final static int STONE = 0;
    public final static int PAPER = 1;
    public final static int SIZOR = 2;

    private MoveButton stone, paper, sizor;

    public MoveTable() {
        super(10);
        setAlignment(Pos.CENTER);
        stone = new MoveButton(MoveButton.STONE);
        paper = new MoveButton(MoveButton.PAPER);
        sizor = new MoveButton(MoveButton.SIZOR);
        getChildren().addAll(stone, paper, sizor);
    }

    public void makeNonInteractable() {
        stone.makeNonInteractable();
        paper.makeNonInteractable();
        sizor.makeNonInteractable();
    }

    public void setButtonAction(int button, EventHandler<ActionEvent> event) {
        switch (button) {
            case STONE:
                stone.setOnAction(event);
                break;
            case PAPER:
                paper.setOnAction(event);
                break;
            case SIZOR:
                sizor.setOnAction(event);
                break;
        }
    }

    public int clickRandomButton() {
        int button = (int)(Math.random() * 3);
        switch (button) {
            case STONE:
                stone.arm();
                paper.disarm();
                sizor.disarm();
                break;
            case PAPER:
                stone.disarm();
                paper.arm();
                sizor.disarm();
                break;
            case SIZOR:
                stone.disarm();
                paper.disarm();
                sizor.arm();
                break;
        }
        return button;
    }
}

class MoveButton extends Button 
{
    public final static String STONE = "🪨";
    public final static String PAPER = "📃";
    public final static String SIZOR = "\u2702";

    public MoveButton(String move) {
        super(move);
        setMinSize(80, 80);
        setFont(Font.font("Segoe UI Emoji", 20));
    }

    public void makeNonInteractable() {
        setDisabled(true);
    }
}
