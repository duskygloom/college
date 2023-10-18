package game;

import game.widgets.GameRoot;
import game.widgets.MoveTable;
import game.widgets.PlayerField;
import game.widgets.PlayerLabel;
import game.widgets.PlaygroundGrid;
import game.widgets.ScoreCard;  
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.image.Image;
import javafx.stage.Stage;

public class App extends Application 
{
    @Override
    public void start(Stage stage) throws Exception {
        setupUI(stage);
        stage.setTitle("Stone Paper Sizor!");
        stage.getIcons().add(new Image(App.class.getResourceAsStream("icon.png")));
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }

    void setupUI(Stage stage) {
        var playground = new PlaygroundGrid();
        var compLabel = new PlayerLabel("Computer");
        var playerLabel = new PlayerField("Player");
        var compMoves = new MoveTable();
        compMoves.makeNonInteractable();
        var playerMoves = new MoveTable();
        var compScore = new ScoreCard();
        var playerScore = new ScoreCard();
        playerMoves.setButtonAction(MoveTable.STONE, event -> {
            commenceRound(MoveTable.STONE, compMoves, compScore, playerScore);
        });
        playerMoves.setButtonAction(MoveTable.PAPER, event -> {
            commenceRound(MoveTable.PAPER, compMoves, compScore, playerScore);
        });
        playerMoves.setButtonAction(MoveTable.SIZOR, event -> {
            commenceRound(MoveTable.SIZOR, compMoves, compScore, playerScore);
        });
        playground.addRow(0, compLabel, playerLabel);
        playground.addRow(1, compMoves, playerMoves);
        playground.addRow(3, compScore, playerScore);
        var root = new GameRoot();
        root.getChildren().add(playground);
        var scene = new Scene(root);
        stage.setScene(scene);
    }

    void commenceRound(int playerMove, MoveTable compMoves, ScoreCard compScore, ScoreCard playerScore) {
        int compMove = compMoves.clickRandomButton();
        if (compMove == playerMove+1 || compMove == playerMove-2)
            compScore.setScore(compScore.getScore() + 1);
        else if (playerMove == compMove+1 || playerMove == compMove-2)
            playerScore.setScore(playerScore.getScore() + 1);
    }
}
