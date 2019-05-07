import py_cpp_edm_interface as cppedm
import pandas as pd
import unittest 

test_func_str = "testing that %s func does not throw err"

#test that the data conversion types good. kinda bloated for this ex but 
#good to be consistent for our testing framework
class test_cpp_interface (unittest.TestCase):

    def __init__(self, *args, **kwargs):
        super(test_cpp_interface, self).__init__(*args, **kwargs)

        #get data for testing
        self.csv_data = pd.read_csv("test_data/circle.csv")
        self.test_input = []
        for col_name in self.csv_data.columns:
            self.test_input.append( (col_name, self.csv_data[col_name].tolist()))

    def test_embed (self):
        print ( test_func_str % "embed" )
        embed_return = cppedm.CPP_Embed(self.test_input, 2,1,"x y", True)

    def test_simplex (self):
        print ( test_func_str % "simplex" )
        simplex_return = cppedm.CPP_Simplex (self.test_input, 
                "1 100", "101 180", 2, 1, 3, 2, "x y","y",True, True)

    def test_smap (self):
        print ( test_func_str % "smap" )
        smap_return = cppedm.CPP_SMap (self.test_input, 
                "1 100", "101 180", 2, 1, 3, 2, 1, "x y","y",True, True)

    def test_ccm (self):
        print ( test_func_str % "ccm" )
        ccm_return = cppedm.CPP_CCM (self.test_input, 2, 1, 3, 2, 
                "x","y","10 80 10",100,True,0,False, True)

    def test_computed_error (self):
        print ( test_func_str % "computed error" )
        computedErr = cppedm.CPP_ComputeError(self.csv_data["x"].tolist(),
                self.csv_data["y"].tolist())

if __name__ == '__main__':
    unittest.main()
