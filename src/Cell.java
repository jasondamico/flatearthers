public class Cell {

    int flood;
    boolean[] wall = {false,false,false,false};

    public Cell(){

    }

    public Cell(boolean[] wall, int flood){
        this.wall = wall;
        this.flood = flood;
    }

    public int getFlood() {
        return flood;
    }

    public boolean[] getWall(){
        return this.wall;
    }

    public void setFlood(int flood){ this.flood=flood; }
    public void setWall(boolean[] wall){ this.wall=wall; }

    public void setEast(boolean x){
        this.wall[0]=x;
    }

    public void setWest(boolean x){
        this.wall[1]=x;
    }

    public void setNorth(boolean x){
        this.wall[2]=x;
    }

    public void setSouth(boolean x){
        this.wall[3]=x;
    }

}
