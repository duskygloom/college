module com.slayderdevs {
    requires javafx.controls;
    requires javafx.fxml;

    opens com.slayderdevs to javafx.fxml;
    exports com.slayderdevs;
}
