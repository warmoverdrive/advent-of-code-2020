#include <iostream>
#include <vector>
#include <chrono>

void NestedLoopSearch(const std::vector<int> &data, int &results);
void HashSearch(const std::vector<int> &data, int &results);

int main()
{
    //  test data
    std::vector<int> expense_report{
        1826, 1895, 1427, 1931, 1651,
        1638, 1507, 1999, 1886, 1824,
        1902, 1995, 1945, 1735, 1823,
        1595, 1936, 1476, 2010, 1833,
        1932, 1772, 1791, 1814, 1783,
        1957, 1901, 1600, 1502, 1521,
        1812, 1974, 1880, 1790, 1672,
        1541, 1807, 426, 1858, 1699,
        1964, 1996, 1983, 1498, 1863,
        1976, 1492, 1930, 1838, 1941,
        1764, 1929, 1897, 2009, 1853,
        1753, 1759, 1860, 1952, 1988,
        1727, 1751, 1943, 1830, 1645,
        1907, 1857, 1714, 1798, 1944,
        1868, 1630, 959, 2003, 1987,
        1890, 1962, 1928, 1872, 1912,
        1709, 1809, 1650, 1980, 1737,
        1898, 1817, 1736, 1991, 1788,
        1776, 1845, 1854, 1963, 1554,
        1949, 1576, 1819, 1960, 699,
        1990, 1757, 1698, 1596, 304,
        1982, 1477, 1961, 1636, 1619,
        1946, 1876, 1592, 1848, 1707,
        1958, 1874, 1867, 52, 1881,
        1665, 1463, 1799, 1979, 677,
        1710, 1869, 1639, 1787, 1633,
        1956, 1457, 1581, 2005, 1782,
        1904, 1910, 62, 1593, 1695,
        1915, 1922, 1797, 1715, 1981,
        1925, 1893, 1562, 1789, 2008,
        1939, 1669, 1992, 1652, 117,
        1609, 1686, 1953, 2007, 599,
        1547, 1959, 1691, 1520, 1444,
        1641, 887, 1579, 1778, 1977,
        1768, 1942, 1713, 1603, 1926,
        1855, 1655, 1673, 1887, 1994,
        1839, 1725, 928, 1771, 1761,
        1971, 1571, 1806, 1821, 1624,
        1701, 1436, 1748, 1921, 1617,
        2004, 1792, 1732, 1740, 1831};

    //	example data
    //    std::vector<int> expense_report{1721, 979, 366, 299, 675, 1456};

    int result = 0;

    auto start = std::chrono::high_resolution_clock::now();
    NestedLoopSearch(expense_report, result);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Nested Loop found " << result << " after " << duration << "ms\n";
    return 0;
}

void NestedLoopSearch(const std::vector<int> &data, int &results)
{
    for (size_t i = 0; i < data.size(); i++)
    {
        for (size_t j = i + 1; j < data.size(); j++)
        {
            for (size_t k = j + 1; k < data.size(); k++)
            {
                if (data.at(i) + data.at(j) + data.at(k) == 2020)
                {
                    results = data.at(i) * data.at(j) * data.at(k);
                    break;
                }
            }
            if (results != 0)
                break;
        }
        if (results != 0)
            break;
    }
}