#include <iostream>
#include <fstream>
#include <unordered_map>
#include <filesystem>

namespace fs = std::filesystem;

[[nodiscard]] fs::path operator""_p(const char * ptr, std::size_t size) {
	return std::filesystem::path(std::string(ptr, size));
}

[[nodiscard]] std::size_t hash_from_path(const fs::path& p) {
	std::ifstream is{ p.string(),
    std::ios::in | std::ios::binary };
	if (!is) { throw errno; }
	std::string s;
	is.seekg(0, std::ios::end);
	s.reserve(is.tellg());
	is.seekg(0, std::ios::beg);
	s.assign(std::istreambuf_iterator<char>{is}, {});
	return std::hash<std::string>{}(s);
}

[[nodiscard]] std::size_t reduce_dupes(const fs::path& dir) {
	std::unordered_map<std::size_t, fs::path> m;
	std::size_t count{ 0 };
	for (const auto& entry :
		fs::recursive_directory_iterator{ dir }) {
		const fs::path p{ entry.path() };
		if (fs::is_directory(p)) { continue; }
		const auto& [it, success] =
			m.try_emplace(hash_from_path(p), p);
		if (!success) {
			std::cout << "Removed " << p.string()
				<< " because it is a duplicate of "
				<< it->second.string() << '\n';
			fs::remove(p);
			fs::create_symlink(fs::absolute(it->second), p);
			++count;
		}
	}
	return count;
}

int main() {
	const auto path = ".."_p;
	auto count = reduce_dupes(path);
	std::cout << count << '\n';
	return 0;
}