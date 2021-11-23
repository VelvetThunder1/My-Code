public class Uniformrandomnumbers {
    public static void main(String[] args){
        double a = Math.random();
        double b = Math.random();
        double c = Math.random();
        double d = Math.random();
        double e = Math.random();
        double ab = Math.max(a,b);
        double abc = Math.max(ab,c);
        double abcd = Math.max(abc,d);
        double max = Math.max(abcd,e);
        System.out.println("Max is " + max);
        double ba = Math.min(a,b);
        double cba = Math.min(ba,c);
        double dcba = Math.min(cba,d);
        double min = Math.min(dcba,e);
        System.out.println("Min is " + min);
        double avg = ((a+b+c+d+e)/5);
        System.out.println("Avg is " + avg);
        System.out.println(a);
        System.out.println(b);
        System.out.println(c);
        System.out.println(d);
        System.out.println(e);
    }
}