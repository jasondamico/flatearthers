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
    	boolean[] returnWall = this.wall.clone();
        return returnWall;
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
    
    public boolean getEast() {
    	return this.wall[0];
    }
    
    public boolean getWest() {
    	return this.wall[1];
    }
    
    public boolean getNorth() {
    	return this.wall[2];
    }
    
    public boolean getSouth() {
    	return this.wall[3];
    }
    /*
    public boolean equals(Object o) {
    	if(!(o instanceof Cell)) {
    		return false;
    	}
    	else {
    		Cell cell = Cell.class.cast(o);
    		if((cell.)
    	}
    }*/
}
