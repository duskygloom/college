package com.slayderdevs;

import javafx.geometry.Insets;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;

public class Widgets 
{
    static class CustomVBox extends VBox {
        public CustomVBox(double padding) {
            super();
            setPadding(new Insets(padding));
        }
    }

    static class CustomHBox extends HBox {
        public CustomHBox(double padding) {
            super();
            setPadding(new Insets(padding));
        }
    }
}
