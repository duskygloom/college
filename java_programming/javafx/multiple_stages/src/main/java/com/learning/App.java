package com.learning;

import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class App extends Application
{
    @Override
    public void start(Stage arg0) throws Exception {
        setupUI(arg0);
    }

    public static void main(String[] args) {
        launch();
    }

    void setupUI(Stage stage) {
        VBox vertical = new VBox(10);
        vertical.setAlignment(Pos.CENTER);
        vertical.getChildren().addAll(new Button("Button 1"), new Button("Button 2"), new Button("Button 3"));
        HBox horizontal = new HBox(10);
        horizontal.setAlignment(Pos.CENTER);
        horizontal.getChildren().addAll(new Button("Button 1"), new Button("Button 2"), new Button("Button 3"));
        Scene scene1 = new Scene(vertical, 300, 300);
        Scene scene2 = new Scene(horizontal, 300, 300);
        stage.setScene(scene1);
        stage.setTitle("Vertical buttons");
        Stage stage2 = new Stage();
        stage2.setScene(scene2);
        stage2.setTitle("Horizontal buttons");
        stage.show();
        stage2.show();
    }
}
