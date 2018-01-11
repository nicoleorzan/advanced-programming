import unittest

class Problem21Test(unittest.TestCase):

    def testSumOfDivisors(self):
        import problem21

        self.assertEqual(problem21.d(220), 284)
        self.assertEqual(problem21.d(284), 220)
    
    def testAmicable(self):
        import problem21

        result = problem21.is_amicable(220, 284)
        self.assertEqual(result, True)
