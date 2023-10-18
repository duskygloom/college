module com.tutorial {
    requires javafx.controls;
    requires javafx.fxml;
    requires javafx.graphics;

    opens com.tutorial to javafx.fxml;
    exports com.tutorial;
}
