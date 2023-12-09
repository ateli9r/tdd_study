from testresult import TestResult

class TestCase:
    def __init__(self, name):
        self.wasRun = None
        self.wasSetup = None
        self.name = name
    
    def setUp(self):
        self.wasRun = None
        self.wasSetUp = 1
    
    def tearDown(self):
        pass
    
    def run(self, result = None):
        if result == None:
            result = TestResult()
            result.testStarted()
        self.setUp()

        try:
            method = getattr(self, self.name)
            method()
        except:
            result.testFailed()

        self.tearDown()
        
        return result

