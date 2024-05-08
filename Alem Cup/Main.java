import java.util.Scanner;
import java.util.List;
import java.util.Random;

enum CharacterType {
    PLAYER,
    MONSTER
}


class Item {
    private int x, y, id;    

    private CharacterType type;

    public void setX(int x) {
        this.x = x;
    }

    public int getX() {
        return x;
    }

    public void setY(int y) {
        this.y = y;
    }

    public int getY() {
        return y;
    }

    public void setType(CharacterType type) {
        this.type = type;
    }

    public CharacterType getType() {
        return type;
    }
}


class Grid {
    private char[][] c;
    private List<Item> items;
    private int n, m, t, k, p;

    public void init() {
        Scanner scan = new Scanner(System.in);                
        String str;

        n = scan.nextInt();
        m = scan.nextInt();
        p = scan.nextInt();
        t = scan.nextInt();
        str = scan.nextLine();
        
        // System.err.println(h + "" + w + "" + player_id + "" + tick + "");

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; ++j)
                c[i][j] = scan.next().charAt(0);
            str = scan.nextLine();                
        }

        k = scan.nextInt();
        
        System.err.println("n:" + k);
        
        type = scan.nextLine();
        
        for (int i = 0; i < n; i++) {
            type = scan.next();
            p_id = scan.nextInt();
            x = scan.nextInt();
            y = scan.nextInt();
            param_1 = scan.nextInt();
            param_2 = scan.nextInt();
            System.err.println(type + "" + p_id + "" + x + "" + y + "" + param_1 + "" + param_2);
        }

        System.err.println("debug mode");

        String actions[] = {"left", "right", "up", "down", "stay"};
        Random r = new Random();
        int random_index = r.nextInt(1000) % 5;
        System.out.println(actions[random_index]);
    }

}

public class Main {
    public static void main(String[] args) {

        while (true) {
            
        }
    }
}




