import javafx.util.Pair; 
import java.util.*; 




public class Main {

    public static void main(String[] args){
    	Maze maze = new Maze(6);
    	boolean[] outwall50 = {true, true, false, true};
    	boolean[] outwall40 = {false, true, true, false};
    	boolean[] outwall41 = {true, false, false, false};
    	boolean[] outwall31 = {true, false, true, false};
    	maze.setCellAtGrid(5, 0, outwall50);
    	maze.setCellAtGrid(4, 0, outwall40);
    	maze.setCellAtGrid(4, 1, outwall41);
    	maze.setCellAtGrid(3, 1, outwall31);
    	
    	System.out.println(maze.toString());
    	floodfill fill1 = new floodfill(maze);
    	
    	
    	boolean[] wall50 = {true, true, false, true};
    	boolean[] wall40 = {false, true, true, false};
    	boolean[] wall41 = {true, false, false, false};
    	boolean[] wall31 = {true, false, true, false};
    	
    	fill1.inMaze.setCellAtGrid(5, 0, wall50);
    	fill1.inMaze.setCellAtGrid(4, 0, wall40);
    	fill1.inMaze.setCellAtGrid(4, 1, wall41);
    	//fill1.inMaze.setCellAtGrid(3, 1, wall31);
    	fill1.curRow = 3;
    	fill1.curCol = 1;
    	//System.out.println(fill1.printInMaze());
    	//System.out.println(fill1.findMinCoord(fill1.inMaze.discoverNeighbour(4, 1), fill1.inMaze.getCell(4, 1)));
    	fill1.floodFill();
    	System.out.println(fill1.printInMaze());
    }

}
