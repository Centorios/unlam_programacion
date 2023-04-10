package edu.unlam.paradigmas;

import java.util.Random;

public class dado {
    private int dType = 6;

    public dado() {
    }

    public dado(int dType) {
        this.dType = dType;
    }


    public int tipoDeDado(){
        return this.dType;
    }

    public int rollear() {
        return new Random().nextInt(dType) + 1;
    }
}
