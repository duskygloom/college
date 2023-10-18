package com.tutorial;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.stage.Stage;


public class App extends Application 
{
    @Override
    public void start(Stage stage) throws Exception {
        setupUI(stage);
    }

    void setupUI(Stage stage) {
        // the base layout
        var baselayout = new VBox();
        baselayout.setPrefSize(400, 200);
        baselayout.setPadding(new Insets(20));
        baselayout.setSpacing(20);
        baselayout.setAlignment(Pos.CENTER);
        // the welcome message
        var welcomelayout = new VBox();
        welcomelayout.setAlignment(Pos.TOP_LEFT);
        var welcomelabel = new Label("Welcome");
        welcomelabel.setFont(Font.font("Georgia", FontWeight.BOLD, 24));
        welcomelayout.getChildren().add(welcomelabel);
        // the username and password fields
        var fieldslayout = new GridPane();
        fieldslayout.setHgap(20);
        fieldslayout.setVgap(10);
        fieldslayout.setAlignment(Pos.CENTER);
        var usernamelabel = new Label("Username:");
        usernamelabel.setFont(Font.font("Candara"));
        var passwordlabel = new Label("Password:");
        passwordlabel.setFont(Font.font("Candara"));
        var usernamefield = new TextField();
        usernamefield.setFont(Font.font("Candara"));
        usernamefield.setPrefWidth(200);
        var passwordfield = new PasswordField();
        passwordfield.setFont(Font.font("Candara"));
        passwordfield.setPrefWidth(200);
        fieldslayout.add(usernamelabel, 0, 0);
        fieldslayout.add(usernamefield, 1, 0);
        fieldslayout.add(passwordlabel, 0, 1);
        fieldslayout.add(passwordfield, 1, 1);
        //  the submit button
        var submitlayout = new VBox();
        submitlayout.setAlignment(Pos.TOP_RIGHT);
        var submitbutton = new Button("Login");
        submitbutton.setPrefSize(120, 30);
        submitbutton.setFont(Font.font("Candera"));
        submitbutton.setOnAction((ActionEvent e) -> 
            {System.out.printf("Username %s tried to login with password %s\n", 
            usernamefield.getText(), passwordfield.getText());});
        submitlayout.getChildren().add(submitbutton);
        // setting up scene
        baselayout.getChildren().addAll(welcomelayout, fieldslayout, submitlayout);
        var scene = new Scene(baselayout);
        scene.getStylesheets().add(App.class.getResource("app.css").toExternalForm());
        stage.setTitle("Login");
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }

}