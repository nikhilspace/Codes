import numpy as np
import pandas as pd



my_data = np.array([np.random.randint(low=0,high=100,size=4)
                    ,np.random.randint(low=0,high=100,size=4),np.random.randint(low=0,high=100,size=4)])


my_column = ("Eleanor", "Chidi", "Tahani", "Jason")


dataframe = pd.DataFrame(data=my_data,columns=my_column)
print(dataframe)

dataframe["Janet"] = dataframe["Tahani"] + dataframe["Jason"]
print(dataframe)
