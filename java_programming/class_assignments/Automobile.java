public class Automobile
{
    public static void main(String[] args) {
        Vehicle firstVehicle = new Vehicle();
        Car secondCar = new Car();
        firstVehicle.showDetails();
        secondCar.brand = "Toyota";
        secondCar.year = 2020;
        secondCar.color = "Pink";
        secondCar.numDoors = 4;
        secondCar.showDetails();
    }
}


class Vehicle
{
    String brand = "Unknown";
    int year = 2023;
    String color = "Unknown";

    public void showDetails() {
        System.out.println("Brand: " + brand);
        System.out.println("Year: " + year);
        System.out.println("Color: " + color);
    }
}


class Car extends Vehicle
{
    int numDoors = 0;

    public void showDetails() {
        super.showDetails();
        System.out.println("Number of doors: " + numDoors);
    }
}
