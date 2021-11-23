public class RandomWalker {
    public static void main(String[] args) {
        int r = Integer.parseInt(args[0]);
        int y2 = 0;
        int x2 = 0;
        int i = 0;
	System.out.println("(" + x2 + ", " + y2 + ")");
        do{
        double step = Math.random();
	    if (step < 0.75) {
                if (step < 0.5) {
                    if (step < 0.25) {
                        x2--;
                    } else {x2++;}
                } else {y2--;}
            } else {y2++;}
        System.out.println("(" + x2 + ", " + y2 + ")");
        i++;
        }while((Math.abs(x2) + Math.abs(y2)) != r);
    System.out.println("steps = " + i);
    }
}
