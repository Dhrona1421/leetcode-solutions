class Solution:
    def getImportance(self, employees, id):
        graph = {}

        for employee in employees:
            graph[employee.id] = employee

        def dfs(employee_id):
            employee = graph[employee_id]

            total = employee.importance

            for subordinate in employee.subordinates:
                total += dfs(subordinate)

            return total

        return dfs(id)