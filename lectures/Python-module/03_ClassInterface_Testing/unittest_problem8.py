"""slice(string,i)
	return tuplanumerica

product(tuplanumerica)
	return mult
"""

import unittest

class TestProblem8(unittest.TestCase):

	self.res1 = (4, 4, 1, 2)
	self.res2 = (0, 8, 2, 3)

	def testSlice4(self):
		import problem8
		
		str_test1 = '42344123'
		str_test2 = '28208239'
		start_pos = 3

		self.assertTupleEqual(problem8.slice4(str_test1, start_pos), self.res1)
		self.assertTupleEqual(problem8.slice4(str_test2, start_pos), self.res2)

	def TuplaProduct(self):
		import problem8

		self.assertEqual(problem8.product(self.res1), 32)
		self.assertEqual(problem8.product(self.res2), 0)



		
