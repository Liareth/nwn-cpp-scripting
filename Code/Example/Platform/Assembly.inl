template <typename First, typename Second, typename ... Params>
std::vector<uint8_t> chain(First first, Second second, Params ... args)
{
    return chain_addr<First, Second, Params ...>(0, first, second, args ...);
}

template <typename First>
std::vector<uint8_t> chain_addr(const uintptr_t address, First first)
{
    return first.bytes(address);
}

template <typename First, typename Second, typename ... Params>
std::vector<uint8_t> chain_addr(const uintptr_t address, First first, Second second, Params ... args)
{
    auto firstData = chain_addr<First>(address, first);
    auto othersData = chain_addr<Second, Params ...>(address + firstData.size(), second, args ...);
    firstData.insert(std::end(firstData), std::begin(othersData), std::end(othersData));
    return firstData;
}