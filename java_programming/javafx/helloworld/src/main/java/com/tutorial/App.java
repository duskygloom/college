package com.tutorial;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.FlowPane;
// import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;
import javafx.stage.Stage;

public class App extends Application
{
    @Override
    public void start(Stage stage) throws Exception {
        setupUI(stage);
    }

    void setupUI(Stage stage) {
        var baselayout = new VBox();
        baselayout.setPrefSize(400, 200);
        baselayout.setAlignment(Pos.CENTER);
        baselayout.setPadding(new Insets(20));
        baselayout.setSpacing(20);
        var hellolabel = new Label("");
        hellolabel.setPrefSize(300, 50);
        hellolabel.setFont(new Font(40));
        hellolabel.setAlignment(Pos.CENTER);
        var buttonlayout = new FlowPane();
        buttonlayout.setAlignment(Pos.CENTER);
        // buttonlayout.setSpacing(10);
        buttonlayout.setHgap(10);
        buttonlayout.setVgap(10);
        var hellobutton = new MyButton("Say hello");
        hellobutton.setOnAction((ActionEvent e) -> {hellolabel.setText("Hello!!");});
        var clearbutton = new MyButton("Clear");
        clearbutton.setOnAction((ActionEvent e) -> {hellolabel.setText("");});
        var closebutton = new MyButton("Close");
        closebutton.setOnAction((ActionEvent e) -> {Platform.exit();});
        buttonlayout.getChildren().setAll(hellobutton, clearbutton, closebutton);
        baselayout.getChildren().addAll(hellolabel, buttonlayout);
        var scene = new Scene(baselayout);
        stage.setScene(scene);
        stage.show();
    }

    class MyButton extends Button {
        public MyButton(String content) {
            super(content);
            setPrefSize(100, 40);
        }
    }

    public static void main(String[] args) {
        launch(args);
    }
}
