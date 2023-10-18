import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.geometry.Pos;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;
import javafx.stage.Stage;


public class HelloFX extends Application
{
	public static void main(String args[]) {
		launch();
	}

	@Override
	public void start(Stage stage) throws Exception {
		setupUI(stage);
		stage.setTitle("Hello!");
		stage.show();
	}

	void setupUI(Stage stage) {
		Label helloText = new Label("Hello from javaFX!!");
		helloText.setFont(Font.font("Consolas", 32));
		VBox root = new VBox(helloText);
		root.setAlignment(Pos.CENTER);
		Scene scene = new Scene(root, 400, 100);
		stage.setScene(scene);
	}
}