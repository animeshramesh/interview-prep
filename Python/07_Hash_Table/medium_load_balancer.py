'''
Implement a load balancer for web servers. It provide the following functionality:

Add a new server to the cluster => add(server_id).
Remove a bad server from the cluster => remove(server_id).
Pick a server in the cluster randomly with equal probability => pick().
'''

'''
Solution:
https://www.geeksforgeeks.org/load-balancing-on-servers-random-algorithm/

Round robin is an ok choice
But randomly selecting servers would yield a better result
'''

class LoadBalancer:
    def __init__(self):
        self.servers = {}

    """
    @param: server_id: add a new server to the cluster
    @return: nothing
    """
    def add(self, server_id):
        self.servers[server_id]=1

    """
    @param: server_id: server_id remove a bad server from the cluster
    @return: nothing
    """
    def remove(self, server_id):
        self.servers.pop(server_id, None)

    """
    @return: pick a server in the cluster randomly with equal probability
    """
    def pick(self):
        import random
        return random.choice(list(self.servers))
