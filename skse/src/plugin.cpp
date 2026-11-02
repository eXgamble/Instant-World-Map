// Instant World Map: SKSE plugin.

#include "WorldMap.h"

namespace
{
	// Own the log before SKSE::Init, and pass Init false so it doesn't truncate/replace it.
	void InitializeLog()
	{
		auto path = logger::log_directory();
		if (!path) {
			SKSE::stl::report_and_fail("Failed to find the SKSE log directory"sv);
		}
		*path /= "InstantWorldMap.log"sv;

		auto sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(path->string(), true);
		auto log = std::make_shared<spdlog::logger>("global log"s, std::move(sink));
		log->set_level(spdlog::level::info);
		log->flush_on(spdlog::level::info);
		spdlog::set_default_logger(std::move(log));
		spdlog::set_pattern("[%H:%M:%S:%e] [%l] %v"s);
	}
}

SKSEPluginLoad(const SKSE::LoadInterface* a_skse)
{
	InitializeLog();
	logger::info("InstantWorldMap loading on game runtime {}", a_skse->RuntimeVersion().string("."));

	SKSE::Init(a_skse, false);
	WorldMap::Install();

	logger::info("InstantWorldMap loaded");
	return true;
}
