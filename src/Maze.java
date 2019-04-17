import javafx.util.Pair; 
import java.util.*; 


public class Maze {

	Cell[][] Maze;
	int length;
	
	//Note the length has to be even. Add shit later
	//This initate a clean maze with only outer walls
	//All flood value is set to 0 for the convinence 
	public Maze(int length) {
		Maze = new Cell[length][length];
		this.length = length;
		
		for (int i = 0; i  < length; i++) {
			for (int j = 0; j < length; j++) {
				Cell cell = new Cell();
				cell.setFlood(0);
				if(i == 0) {
					cell.setNorth(true);
				}
				else if(i == this.length -1) {
					cell.setSouth(true);
				}
				
				if(j == 0) {
					cell.setWest(true);
				}
				else if(j == this.length -1) {
					cell.setEast(true);
				}
				this.Maze[i][j] = cell;
						
			}
		}
	}
	
	public Cell getCell(int row, int col) {
		return this.Maze[row][col];
	}
	
	public String toString() {
		String returnString = "";
		for(int i = 0; i<this.length; i++) {
			//Print upper wall
			for(int j = 0;j<this.length;j++) {
				Cell curCell = this.Maze[i][j];
				if(curCell.getNorth()) {
					returnString += " ---";
				}
				else {
					returnString += "    ";
				}
			}
			returnString +="\n";
			for(int k = 0; k<this.length;k++) {
				Cell curCell = this.Maze[i][k];
				if(curCell.getWest()) {
					returnString += "|";
				}
				else {
					returnString += " ";
				}
				
				returnString += " ";
				returnString += Integer.toString(curCell.getFlood());
				returnString += " ";
			}
			
			//Add the rightmost wall
			returnString += "|\n";
			
			
		}
		//Add bottom walls
		for(int j = 0; j< this.length; j++) {
			returnString += " ---";
		}
		return returnString;
	}
	
	// --- ---
	//|   | 2 |
	
	//Set the target cell and its neiber to the given wall status
	public void setCellAtGrid(int row, int col, boolean[] stats) {
		Cell curCell = this.Maze[row][col];
		curCell.setWall(stats);
		
		this.updateNeighbour(row, col, stats);
	}
	
	public void setFloodAtGrid(int row, int col, int val) {
		Cell curCell = this.Maze[row][col];
		curCell.setFlood(val);
	}
	
	public void updateNeighbour(int row, int col, boolean[] stats) {
		//Reminder index to orientation is 0 - East, 1 - West, 2 - North, 3 - South
		boolean east = stats[0], west = stats[1], north = stats[2], south = stats[3];
		//Update upper cell
		if(row != 0) {
			this.Maze[row-1][col].setSouth(north);
		}
		if(row != this.length-1) {
			this.Maze[row+1][col].setNorth(south);
		}
		if(col != 0) {
			this.Maze[row][col-1].setEast(west);
		}
		if(col != this.length-1) {
			this.Maze[row][col+1].setWest(east);
		}
	}
	
	//Generate random maze starting from the center
	public void mazeGenExpand() {
		ArrayList<Pair<Integer,Integer>> discoverable = new ArrayList<Pair<Integer,Integer>>();
		HashSet<Pair<Integer,Integer>> visited = new HashSet<Pair<Integer,Integer>>();
		
		int[] cenRow = {this.length/2,this.length/2-1};
		int[] cenCol = {this.length/2,this.length/2-1};
		
		//Add in center four cells that is the goal
		for(int r:cenRow) {
			for(int c:cenCol) {
				Pair<Integer,Integer> coord = new Pair<Integer,Integer>(r, c);
				visited.add(coord);
			}
		}
		
		//Note key is row and value is column
		for(Pair<Integer, Integer> center : visited) {
			ArrayList<Pair<Integer,Integer>> surroundings = this.discoverNeighbour(center.getKey(), center.getValue());
			//Add the immediate surrounding cells to discoverable
			for (Pair<Integer, Integer> surrounding: surroundings) {
				if(!visited.contains(surrounding) && !discoverable.contains(surrounding)) {
					discoverable.add(surrounding);
				}
			}
		}
		
		//The initization is finished
		
		Random r = new Random();
		
		//Start explore the discoverable
		while(!discoverable.isEmpty()) {
			int size = discoverable.size();
			//Fetch a random cell from discoverable
			int index = r.nextInt(size);
			Pair<Integer, Integer> curCell = discoverable.get(index);
			int row=curCell.getKey(), col=curCell.getValue();
			
			
		}	
	}
	
	public ArrayList<Pair<Integer,Integer>> discoverNeighbour(int r, int c){
		ArrayList<Pair<Integer,Integer>> returnList = new ArrayList<Pair<Integer,Integer>>();
		if(r != 0) {
			Pair<Integer, Integer> left = new Pair<Integer, Integer>(r-1,c);
			returnList.add(left);
		}
		if(r != this.length-1) {
			Pair<Integer, Integer> left = new Pair<Integer, Integer>(r+1,c);
			returnList.add(left);
		}
		if(c != 0) {
			Pair<Integer, Integer> left = new Pair<Integer, Integer>(r,c-1);
			returnList.add(left);
		}
		if(c != this.length -1) {
			Pair<Integer, Integer> left = new Pair<Integer, Integer>(r,c+1);
			returnList.add(left);
		}
		return returnList;
	}
	
	public int getLength() {
		return this.length;
	}
}
