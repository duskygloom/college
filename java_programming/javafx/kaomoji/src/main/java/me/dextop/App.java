package me.dextop;

import java.io.File;
import java.io.FileNotFoundException;
import java.net.URISyntaxException;
import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.geometry.Pos;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.image.Image;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;


public class App extends Application 
{

    ArrayList<String> kaomojiList = new ArrayList<String>();
    Random random = new Random(System.currentTimeMillis());

    @Override
    public void start(Stage stage) {
        fetchKaomojis("kaomojis.txt");
        initUI(stage);
    }

    void initUI(Stage stage) {
        var baseLayout = new VBox();
        baseLayout.setSpacing(20);
        baseLayout.setAlignment(Pos.CENTER);
        var buttonLayout = new HBox();
        buttonLayout.setSpacing(10);
        buttonLayout.setAlignment(Pos.CENTER);
        var kaomojiLabel = new Label("");
        kaomojiLabel.setFont(new Font("sans", 24));
        var showButton = new Button("Show");
        showButton.setPrefSize(100, 30);
        showButton.setOnAction((ActionEvent e) -> 
            {kaomojiLabel.setText(getRandomKaomoji());});
        var clearButton = new Button("Clear");
        clearButton.setPrefSize(100, 30);
        clearButton.setOnAction((ActionEvent e) ->
            {kaomojiLabel.setText("");});
        buttonLayout.getChildren().addAll(showButton, clearButton);
        baseLayout.getChildren().addAll(kaomojiLabel, buttonLayout);
        var scene = new Scene(baseLayout, 400, 200);
        stage.setTitle("Kaomojis");
        stage.setScene(scene);
        stage.getIcons().add(new Image(App.class.getResourceAsStream("icon.jpg")));
        stage.show();
    }

    void fetchKaomojis(String resource) {
        try {
            var file = new File(App.class.getResource(resource).toURI());
            var scanner = new Scanner(file, "utf-8");
            while (scanner.hasNextLine())
                kaomojiList.add(scanner.nextLine().strip());
            scanner.close();
        } catch (URISyntaxException e) {
            System.out.println("Incorrect URI syntax for resource: " + resource);
        } catch (FileNotFoundException e) {
            System.out.println("File not found for resource: " + resource);
        }
    }

    String getRandomKaomoji() {
        int randomIndex = random.nextInt(kaomojiList.size());
        return kaomojiList.get(randomIndex);
    }

    public static void main(String args[]) {
        launch(args);
    }
}
