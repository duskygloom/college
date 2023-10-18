public class InheritanceExample
{
	public static void main(String args[]) {
		Cat cat = new Cat("Kitty");
		cat.speak("hello everynyan");
	}
}


class Animal {
	String name, voice;
	Animal(String name, String voice) {
	  	this.name = name;
	  	this.voice = voice;
	}
	void speak(String text) {
		System.out.println(name + ": " + text + " " + voice + "!");
	}
}

class Cat extends Animal {
	Cat(String name) {
	  	super(name, "meow");
	}
}

