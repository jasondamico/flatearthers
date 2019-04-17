import java.util.*;
import javafx.util.Pair; 

public class floodfill {
	public Maze outMaze;
	public Maze inMaze;
	
	public int curRow;
	public int curCol;
	
	
	//OutMaze is the maze that robot is navigating through,
	//but the robot don't know the full picture of the maze yet
	
	//The inMaze is the internal maze that the robot knows
	public floodfill(Maze inputMaze) {
		this.outMaze = inputMaze;
		int length = this.outMaze.getLength();
		this.inMaze = new Maze(length);
		
		for(int i=0; i<length;i++) {
			for(int j=0; j<length;j++) {
				int minXDis = Math.min(Math.abs(length/2-j), Math.abs(length/2-j-1));
				int minYDis = Math.min(Math.abs(length/2-i), Math.abs(length/2-i-1));
				int totalDis = minXDis+minYDis;
				this.inMaze.setFloodAtGrid(i, j, totalDis);
			}
		}
	}
	
	public String printInMaze() {
		return this.inMaze.toString();
	}
	
	public String printOutMaze() {
		return this.outMaze.toString();
	}
	
	//Given a current maze state, update the maze's flood value
	public void floodFill() {
		Cell curCell = this.inMaze.getCell(this.curRow, this.curCol);
		
		//Simulating the wall discovery process. Will be more nasty in bot
		this.inMaze.setCellAtGrid(curRow, curCol, this.outMaze.getCell(curRow, curCol).getWall());
		
		//System.out.println(this.outMaze.getCell(curRow, curCol).getWall().toString());
		ArrayList<Pair<Integer, Integer>> neighbour = this.inMaze.discoverNeighbour(curRow, curCol);
		
		Pair<Integer,Integer> minCoord = findMinCoord(this.curRow,curCol,neighbour, curCell);
		System.out.println(minCoord.toString());
		Cell minCell = this.inMaze.getCell(minCoord.getKey(), minCoord.getValue());
		int minVal = minCell.getFlood() - curCell.getFlood();
		System.out.println(this.printInMaze());
		System.out.println(minVal);
		//If the minVal is not -1, it means we need to update the value and the corresponding neighbour to 
		//the correct new flood value
		if(minVal != -1) {
			Stack<Pair<Integer, Integer>> coordStack = new Stack<Pair<Integer, Integer>>();
			Pair<Integer, Integer> curCoord = new Pair<Integer, Integer>(curRow, curCol);
			coordStack.push(curCoord);
			int counter = 0;
			while(!coordStack.empty()) {
				System.out.println(coordStack.toString());
				curCoord = coordStack.pop();
				Cell tempCell = this.inMaze.getCell(curCoord.getKey(), curCoord.getValue());
				neighbour = this.inMaze.discoverNeighbour(curCoord.getKey(), curCoord.getValue());
				
				minCoord = findMinCoord(curCoord.getKey(), curCoord.getValue(),neighbour, tempCell);
				minCell = this.inMaze.getCell(minCoord.getKey(), minCoord.getValue());
				minVal = minCell.getFlood() - tempCell.getFlood();
				
				System.out.println(minVal);
				System.out.println(minCoord);
				if(minVal != -1 && minCell.getFlood() != 0) {
					tempCell.setFlood(minCell.getFlood()+1);
					for(Pair<Integer, Integer> coord:neighbour) {
						coordStack.push(coord);
					}
				}
				System.out.println(this.printInMaze());
				//counter++;
				if(counter > 5) {
					break;
				}
			}
		}
		
		
		
	}
	
	//Find the min distance to the availiable cells(the not blocked cells). Ideally the
	//min val should be -1 because that means we can simply go greedy and go for that direction.
	public Pair<Integer, Integer> findMinCoord(int row, int col,ArrayList<Pair<Integer, Integer>> neighbour, Cell curCell) {
		int length = this.inMaze.getLength();
		int minVal = length*length+1;
		int neighbourFlood,distance;
		Pair<Integer, Integer> returnCoord = new Pair<Integer, Integer>(3,3);//Magic number cause I need to initize one
		//Find the minimal distance to the neighbour cells(The one that is not blocked by walls)
		for(Pair<Integer,Integer> grid : neighbour) {
			//Note key is row
			if(grid.getKey()-row == 0) {
				if(grid.getValue() - col == 1 && !curCell.getEast()) {
					neighbourFlood = this.inMaze.getCell(grid.getKey(),grid.getValue()).getFlood();
					distance = neighbourFlood - curCell.getFlood();
					if(distance < minVal) {
						minVal = distance;
						returnCoord = grid;
					}
					
				}
				else if(grid.getValue() - col == -1 && !curCell.getWest()){
					neighbourFlood = this.inMaze.getCell(grid.getKey(),grid.getValue()).getFlood();
					distance = neighbourFlood - curCell.getFlood();
					if(distance < minVal) {
						minVal = distance;
						returnCoord = grid;
					}
				}
			}
			else {
				if(grid.getKey() - row == 1 && !curCell.getSouth()) {
					neighbourFlood = this.inMaze.getCell(grid.getKey(),grid.getValue()).getFlood();
					distance = neighbourFlood - curCell.getFlood();
					if(distance < minVal) {
						minVal = distance;
						returnCoord = grid;
					}
				}
				else if(grid.getKey() - row == -1 && !curCell.getNorth()) {
					neighbourFlood = this.inMaze.getCell(grid.getKey(),grid.getValue()).getFlood();
					distance = neighbourFlood - curCell.getFlood();
					if(distance < minVal) {
						minVal = distance;
						returnCoord = grid;
					}
				}
			}
		}
		
		return returnCoord;
	}
}
