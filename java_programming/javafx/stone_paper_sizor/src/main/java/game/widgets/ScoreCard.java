package game.widgets;

import javafx.geometry.Pos;
import javafx.scene.control.Label;
import javafx.scene.layout.HBox;
import javafx.scene.text.Font;

public class ScoreCard extends HBox 
{
    private Label scoreLabel;

    public ScoreCard() {
        super(10);
        setAlignment(Pos.BOTTOM_CENTER);
        setMinHeight(80);
        scoreLabel = new Label();
        scoreLabel.setText("0");
        scoreLabel.setMinHeight(30);
        scoreLabel.setFont(Font.font("Consolas", 30));
        var pointsText = new Label("points");
        pointsText.setFont(Font.font("Consolas", 10));
        getChildren().addAll(scoreLabel, pointsText);
    }

    public void setScore(int score) {
        scoreLabel.setText(Integer.toString(score));
    }

    public int getScore() {
        return Integer.parseInt(scoreLabel.getText());
    }
}
