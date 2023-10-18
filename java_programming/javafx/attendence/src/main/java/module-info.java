module util {
    requires javafx.controls;
    requires javafx.fxml;

    opens util to javafx.fxml;
    exports util;
}
