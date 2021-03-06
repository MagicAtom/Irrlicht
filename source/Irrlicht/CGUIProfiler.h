// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h
// Written by Michael Zeilfelder

#ifndef IRR_C_GUI_PROFILER_H_INCLUDED
#define IRR_C_GUI_PROFILER_H_INCLUDED

#include "IrrCompileConfig.h"
#ifdef _IRR_COMPILE_WITH_GUI_

#include "IGUIProfiler.h"

namespace irr
{

class IProfiler;
struct SProfileData;

namespace gui
{
	class IGUITable;

	//! Element to display profiler information
	class CGUIProfiler : public IGUIProfiler
	{
	public:
		//! constructor
		CGUIProfiler(IGUIEnvironment* environment, IGUIElement* parent, s32 id, core::rect<s32> rectangle, IProfiler* profiler);

		//! Show first page of profile data
		virtual void firstPage(bool includeOverview) IRR_OVERRIDE;

		//! Show next page of profile data
		virtual void nextPage(bool includeOverview) IRR_OVERRIDE;

		//! Show previous page of profile data
		virtual void previousPage(bool includeOverview) IRR_OVERRIDE;

		//! Try to show as many group-pages together as possible instead of showing at most one group per page.
		/** \param groupsTogether When true show several groups on one page, when false show max. one group per page. Default is false. */
		virtual void setShowGroupsTogether(bool groupsTogether) IRR_OVERRIDE;

		//! Can several groups be displayed per page?
		virtual bool getShowGroupsTogether() const IRR_OVERRIDE;

		//! Sets another skin independent font.
		virtual void setOverrideFont(IGUIFont* font) IRR_OVERRIDE;

		//! Gets the override font (if any)
		virtual IGUIFont* getOverrideFont() const IRR_OVERRIDE;

		//! Get the font which is used right now for drawing
		virtual IGUIFont* getActiveFont() const IRR_OVERRIDE;

		//! Sets whether to draw the background. By default disabled,
		virtual void setDrawBackground(bool draw) IRR_OVERRIDE;

		//! Checks if background drawing is enabled
		/** \return true if background drawing is enabled, false otherwise */
		virtual bool isDrawBackgroundEnabled() const IRR_OVERRIDE;

		//! Allows to freeze updates which makes it easier to read the numbers
		virtual void setFrozen(bool freeze) IRR_OVERRIDE;

		//! Are updates currently frozen
		virtual bool getFrozen() const IRR_OVERRIDE;

		//! Filters prevents data that doesn't achieve the conditions from being displayed
		virtual void setFilters(irr::u32 minCalls, irr::u32 minTimeSum, irr::f32 minTimeAverage, irr::u32 minTimeMax) IRR_OVERRIDE;

		virtual IGUIElement* getElementFromPoint(const core::position2d<s32>& point) IRR_OVERRIDE
		{
			// This element should never get focus from mouse-clicks
			return 0;
		}

		virtual void draw() IRR_OVERRIDE;

	protected:

		void updateDisplay();
		void fillRow(u32 rowIndex, const SProfileData& data, bool overviewTitle, bool groupTitle);
		u32 addDataToTable(u32 rowIndex, u32 dataIndex, u32 groupIndex);
		void rebuildColumns();

		IProfiler * Profiler;
		irr::gui::IGUITable* DisplayTable;
		irr::u32 CurrentGroupIdx;
		irr::s32 CurrentGroupPage;
		irr::s32 NumGroupPages;
		bool DrawBackground;
		bool Frozen;
		bool UnfreezeOnce;
		bool ShowGroupsTogether;
		irr::u32 MinCalls;
		irr::u32 MinTimeSum;
		irr::f32 MinTimeAverage;
		irr::u32 MinTimeMax;
	};

} // end namespace gui
} // end namespace irr

#endif // _IRR_COMPILE_WITH_GUI_

#endif
