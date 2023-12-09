from wasrun import WasRun
from testcase import TestCase
from testresult import TestResult
from testsuite import TestSuite

class TestCaseTest(TestCase):
    def setUp(self):
        self.result = TestResult()
    
    def testTemplateMethod(self):
        self.test = WasRun('testMethod')
        self.test.run()
        assert('setUp testMethod tearDown ' == self.test.log)
    
    def testResult(self):
        result = TestResult()
        self.test = WasRun('testMethod')
        result = self.test.run(result)
        assert('1 run, 0 failed' == result.summary())
    
    def testFailedResult(self):
        self.test = WasRun('testBrokenMethod')
        result = self.test.run()
        # print('summary: ', result.summary())
        assert('1 run, 0 failed' == result.summary())

    def testFailedResultFormating(self):
        result = TestResult()
        result.testStarted()
        result.testFailed()
        assert('1 run, 1 failed' == result.summary())
    
    def testSuit(self):
        result = TestResult()
        suite = TestSuite()
        suite.add(WasRun('testMethod'))
        suite.add(WasRun('testBrokenMethod'))
        suite.run(result)
        assert('2 run, 1 failed' == result.summary())

# TestCaseTest('testRunning').run()
# TestCaseTest('testSetUp').run()

# TestCaseTest('testTemplateMethod').run()
# TestCaseTest('testResult').run()
# TestCaseTest('testFailedResultFormating').run()
# TestCaseTest('testFailedResult').run()
TestCaseTest('testSuit').run()

