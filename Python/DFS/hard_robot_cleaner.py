"""
Need to keep track of cells which are visited
You would also have to come back to the cell after a dfs operation
"""
class Solution(object):

    def dfs(self, robot, x, y, cur_dir):
        self.visited.add((x,y))
        robot.clean()

        for i in range(4):
            next_dir = (cur_dir + i) % 4
            new_x = x + self.dirs[next_dir][0]
            new_y = y + self.dirs[next_dir][1]

            if (new_x, new_y) not in self.visited and robot.move():
                self.dfs(robot, new_x, new_y, next_dir)

            robot.turnRight()

        # To go back to current cell
        robot.turnRight()
        robot.turnRight()
        robot.move()
        robot.turnRight()
        robot.turnRight()

    def cleanRoom(self, robot):
        self.visited = set()

        # It has to be in this order
        self.dirs = [(0,1), (1,0), (0,-1),(-1,0)]

        self.dfs(robot, 0, 0, 0)
