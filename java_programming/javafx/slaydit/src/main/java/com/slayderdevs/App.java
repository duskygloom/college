package com.slayderdevs;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.SplitPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Paint;
import javafx.scene.shape.Rectangle;
import javafx.stage.Stage;

import java.util.Stack;

import com.slayderdevs.Widgets.*;


public class App extends Application
{
    @Override
    public void start(Stage stage) throws Exception {
        setupFeed(stage);
    }

    void setupFeed(Stage stage) {
        var root = new VBox();
        var cols = new HBox();
        var comm = new VBox();
        comm.getChildren().add(new Label("Communities"));
        var feed = new ScrollPane();
        var tabs = new VBox();
        tabs.getChildren().add(new Label("Tabs"));
        cols.getChildren().addAll(comm, feed, tabs);
        root.getChildren().add(cols);
        Scene scene = new Scene(root, 1000, 600);
        stage.setScene(scene);
        stage.setTitle("Feed");
        stage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
