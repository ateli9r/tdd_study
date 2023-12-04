class TestCase:
    def __init__(self, name):
        self.wasRun = None
        self.wasSetup = None
        self.name = name
    
    def setUp(self):
        print('!!! setUp')
        self.wasRun = None
        self.wasSetUp = 1
        # pass
    
    def run(self):
        self.setUp()
        method = getattr(self, self.name)
        method()

