module me.dextop {
    requires javafx.controls;
    requires javafx.fxml;

    opens me.dextop to javafx.fxml;
    exports me.dextop;
}
