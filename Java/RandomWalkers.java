public class RandomWalkers {
    public static void main(String[] args) {
        int r = Integer.parseInt(args[0]);
        int trials = Integer.parseInt(args[1]);
        int y2 = 0;
        int x2 = 0;
        int i = 0;
        int total = 0;
        for (int j = 1; j <= trials/j; j++) {
            do{
                double step = Math.random();
                if (step < 0.75) {
                    if (step < 0.5) {
                        if (step < 0.25) {
                            x2--;
                        } else {x2++;}
                    } else {y2--;}
                } else {y2++;}
            i++;
            }while((Math.abs(x2) + Math.abs(y2)) != r);
        total = total + i;
        }
        System.out.println("average number of steps = " + (total/trials));
    }
}
