public class circle {
    public int radius;
    public circle(int radius) {
        this.radius = radius;
    }
    public double getArea() {
        return Math.PI * Math.pow(this.radius, 2);
    }
    public double getPerimeter() {
        return 2 * Math.PI * this.radius;
    }
    public int getRadius() {
        return this.radius;
    }
}
